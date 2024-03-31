package opengl.panjq.com.opengl_demo;

import android.content.ComponentName;
import android.content.Context;
import android.content.Intent;
import android.opengl.GLSurfaceView;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

import android.app.ActivityManager;
import android.content.pm.ConfigurationInfo;
import android.util.Log;

import static android.opengl.GLSurfaceView.RENDERMODE_CONTINUOUSLY;
import static android.opengl.GLSurfaceView.RENDERMODE_WHEN_DIRTY;

import com.example.namespace.R;


public class MainActivity extends AppCompatActivity implements View.OnClickListener{
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        Button btDraw = findViewById(R.id.btDraw);
        btDraw.setOnClickListener(MainActivity.this);
    }

    @Override
    protected void onResume() {
        super.onResume();
    }

    public void onClick(View view){


        Intent intent = new Intent();
        // 在 Intent 中添加需要传递的参数，以键值对的形式存储
        intent.putExtra("Action", ((Button)view).getText()); // 这里的 "key" 是参数的名称，"value" 是参数的值

//      //跳转其他APP的固定页面，需要APP的包名，activity的全路径
//       //在要跳转的APP的activity的配置添加 android:exported="true"，将activity暴露出来
        ComponentName name = new ComponentName("opengl.panjq.com.opengl_demo","opengl.panjq.com.opengl_demo.DrawActivity");
        intent.setComponent(name);
        startActivity(intent);
    }
}
