package edu.bd.ewu.contact_form;

import androidx.activity.result.ActivityResult;
import androidx.activity.result.ActivityResultCallback;
import androidx.activity.result.ActivityResultLauncher;
import androidx.activity.result.contract.ActivityResultContracts;
import androidx.annotation.NonNull;
import androidx.annotation.RequiresApi;
import androidx.appcompat.app.AlertDialog;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.app.ActivityCompat;
import androidx.core.content.ContextCompat;
import android.Manifest;
import android.content.DialogInterface;
import android.content.Intent;
import android.content.SharedPreferences;
import android.content.pm.PackageManager;
import android.graphics.Bitmap;
import android.net.Uri;
import android.os.Build;
import android.os.Bundle;
import android.provider.MediaStore;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ImageButton;
import android.widget.ImageView;
import android.widget.Toast;
import java.io.ByteArrayOutputStream;
import java.io.IOException;
import java.util.Base64;

public class Contact_Form extends AppCompatActivity {

    ImageView imageView;
    EditText name, email, phone_number01, phone_number02;
    Button save, cancel;
    SharedPreferences pref;
    ActivityResultLauncher<Intent> activityResultLauncher;
    String  error_messages = "";
    String name_str, email_str, number_str01, number_str02, Image_str;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_contact_form);

        imageView = findViewById(R.id.image_view);
        name = findViewById(R.id.name);
        email = findViewById(R.id.email);
        phone_number01 = findViewById(R.id.phone_number01);
        phone_number02 = findViewById(R.id.phone_number02);
        save = findViewById(R.id.save);
        cancel = findViewById(R.id.cancel);

        pref = getSharedPreferences("contact_form", MODE_PRIVATE);

        activityResultLauncher = registerForActivityResult(new ActivityResultContracts.StartActivityForResult(), new ActivityResultCallback<ActivityResult>() {
            @RequiresApi(api = Build.VERSION_CODES.O)
            @Override
            public void onActivityResult(ActivityResult result) {

                Intent data = result.getData();
                //check condition
                if(result.getResultCode() == RESULT_OK && data != null){
                    //when result is ok
                    //initial uri
                    Uri uri = data.getData();
                    try {
                        //initialize bitmap
                        Bitmap bitmap = MediaStore.Images.Media.getBitmap(getContentResolver(), uri);
                        //Initialize byte stream
                        ByteArrayOutputStream stream = new ByteArrayOutputStream();
                        //compress bitmap
                        bitmap.compress(Bitmap.CompressFormat.JPEG, 100, stream);
                        //initialize byte array
                        byte[] bytes = stream.toByteArray();
                        //get base64
                        Image_str = Base64.getEncoder().encodeToString(bytes);

                    } catch (IOException e) {
                        e.printStackTrace();
                    }
                }
            }
        });

        imageView.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if(ContextCompat.checkSelfPermission(Contact_Form.this,
                        Manifest.permission.WRITE_EXTERNAL_STORAGE) != PackageManager.PERMISSION_GRANTED){
                    ActivityCompat.requestPermissions(Contact_Form.this, new String[]{
                            Manifest.permission.WRITE_EXTERNAL_STORAGE}, 100);
                }
                else {
                    selectImage();
                }
            }
        });

        save.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {

                if(name.length() < 3 || email.length() < 11 ||
                        phone_number01.length() < 11 || phone_number01.length() > 13 ||
                        phone_number02.length() < 11 || phone_number02.length() > 13){
                    error_messages+="Invalid Inputs!";
                }

                SharedPreferences.Editor editor = pref.edit();

                if (error_messages.length() == 0){

                    name_str = name.getText().toString();
                    email_str = email.getText().toString();
                    number_str01 = phone_number01.getText().toString();
                    number_str02 = phone_number02.getText().toString();

                    editor.putString("name", name_str);
                    editor.putString("email", email_str);
                    editor.putString("number_home", number_str01);
                    editor.putString("number_office", number_str02);
                    editor.putString("Image64", Image_str);
                    editor.putBoolean("flag", true);
                    editor.apply();
                    Toast.makeText(Contact_Form.this, "Saved Successfully!",Toast.LENGTH_LONG).show();

                    //showDialog("Do you want to save this event info?", "info", "Yes","No");
                    Intent iHome = new Intent(Contact_Form.this, Home.class);
                    startActivity(iHome);
                }
                else{
                    showDialog(error_messages, "Error", "Ok", "Back");
                }
            }
        });

        cancel.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {

                SharedPreferences.Editor editor = pref.edit();

                editor.putBoolean("flag", false);
                editor.apply();

                Intent iHome = new Intent(Contact_Form.this, MainActivity.class);
                startActivity(iHome);

                /*Intent i = new Intent(Intent.ACTION_MAIN);
                i.setFlags(Intent.FLAG_ACTIVITY_CLEAR_TOP);
                i.addCategory(Intent.CATEGORY_HOME);
                startActivity(i);*/
                finish();
                System.exit(0);
            }
        });

    }

    private void selectImage() {
        imageView.setImageBitmap(null);
        //initialized intent
        Intent intent = new Intent();
        //set type
        intent.setType("image/*");
        intent.setAction(Intent.ACTION_GET_CONTENT);
        //Start activity result
        //startIntentSenderForResult(Intent.createChooser(intent,"Select Image"), 100);
        activityResultLauncher.launch(intent);
    }

    @Override
    public void onRequestPermissionsResult(int requestCode, @NonNull String[] permissions, @NonNull int[] grantResults) {
        super.onRequestPermissionsResult(requestCode, permissions, grantResults);
        // create condition
        if (requestCode == 100 && grantResults[0] == PackageManager.PERMISSION_GRANTED){
            //when permission is granted
            //call method
            selectImage();
        }
        else{
            //when permission denied
            Toast.makeText(getApplicationContext(), "Permission Denied!", Toast.LENGTH_SHORT).show();
        }
    }

    /*@RequiresApi(api = Build.VERSION_CODES.O)
    @Override
    protected void onActivityResult(int requestCode, int resultCode, @Nullable Intent data) {
        super.onActivityResult(requestCode, resultCode, data);

        //check condition
        if(requestCode == 100 && resultCode && resultCode == RESULT_OK && data != null){
            //when result is ok
            //initial uri
            Uri uri = data.getData();
            try {
                //initialize bitmap
                Bitmap bitmap = MediaStore.Images.Media.getBitmap(getContentResolver(), uri);
                //Initialize byte stream
                ByteArrayOutputStream stream = new ByteArrayOutputStream();
                //compress bitmap
                bitmap.compress(Bitmap.CompressFormat.JPEG, 100, stream);
                //initialize byte array
                byte[] bytes = stream.toByteArray();
                //get base64
                Image_str = Base64.getEncoder().encodeToString(bytes);

            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }*/

    private void showDialog(String message, String title, String btn01, String btn02){
        AlertDialog.Builder builder = new AlertDialog.Builder(this);

        builder.setMessage(message);
        builder.setTitle(title);

        builder.setCancelable(false).setPositiveButton(btn01, new DialogInterface.OnClickListener() {
            @Override
            public void onClick(DialogInterface dialog, int id) {
                System.out.println("Button was clicked");
                //Util.getInstance().deleteByKey(MainActivity.this, key);
                dialog.cancel();
                //loaddata();
                //adapter.notifydataSetChanged();
                //lvEvents.notifyAll();
            }
        }).setNegativeButton(btn02, new DialogInterface.OnClickListener() {
            @Override
            public void onClick(DialogInterface dialog, int which) {
                dialog.cancel();

            }
        });
        AlertDialog alert = builder.create();
        //alert.setTitle("Error Dialog");
        alert.show();
    }
}