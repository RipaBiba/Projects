package edu.bd.ewu.contact_form;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.content.SharedPreferences;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.os.Bundle;
import android.util.Base64;
import android.view.View;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.TextView;

public class Home extends AppCompatActivity {

    ImageView show_image;
    TextView view_name, view_email, view_number01, view_number02;
    Button back, close;
    String name_str_v, email_str_v, number_str01_v, number_str02_v, image_str_v;
    SharedPreferences pref;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_home);

        show_image = findViewById(R.id.show_image);

        view_name = findViewById(R.id.view_name);
        view_email = findViewById(R.id.view_email);
        view_number01 = findViewById(R.id.view_number01);
        view_number02 = findViewById(R.id.view_number02);

        back = findViewById(R.id.back);
        close = findViewById(R.id.close);

        pref = getSharedPreferences("contact_form", MODE_PRIVATE);

        name_str_v = pref.getString("name", "");
        email_str_v = pref.getString("email", "");
        number_str01_v = pref.getString("number_home", "");
        number_str02_v = pref.getString("number_office", "");
        image_str_v = pref.getString("Image64","");

        //decode base64
        byte[] bytes = Base64.decode(image_str_v,Base64.DEFAULT);
        // initialize bitmap
        Bitmap bitmap = BitmapFactory.decodeByteArray(bytes,0,bytes.length);
        //set bitmap on image view
        show_image.setImageBitmap(bitmap);

        view_name.setText(name_str_v);
        view_email.setText(email_str_v);
        view_number01.setText(number_str01_v);
        view_number02.setText(number_str02_v);

        SharedPreferences.Editor editor = pref.edit();

        back.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {

                editor.putBoolean("flag", false);
                editor.apply();

                Intent iHome = new Intent(Home.this, Contact_Form.class);
                startActivity(iHome);
            }
        });

        close.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {

                editor.putBoolean("flag", true);
                editor.apply();

                Intent i = new Intent(Intent.ACTION_MAIN);
                i.setFlags(Intent.FLAG_ACTIVITY_CLEAR_TOP);
                i.addCategory(Intent.CATEGORY_HOME);
                startActivity(i);
                finish();
                System.exit(0);
            }
        });
    }
}