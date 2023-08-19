package edu.bd.ewu.lab_exam;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;

public class LogInActivity extends AppCompatActivity {

    private EditText loginEmail, logInPassWord;
    private Button LogIn;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_log_in);

        loginEmail = findViewById(R.id.logInemail);
        logInPassWord = findViewById(R.id.logInPassWord);
        LogIn = findViewById(R.id.signIn);

        LogIn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                startActivity(new Intent(LogInActivity.this, VerificationActivity.class));
                finish();
            }
        });
    }
}