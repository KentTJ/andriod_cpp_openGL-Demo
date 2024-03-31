package opengl.panjq.com.opengl_demo;

import static android.opengl.GLSurfaceView.RENDERMODE_CONTINUOUSLY;

import android.app.ActivityManager;
import android.content.Context;
import android.content.pm.ConfigurationInfo;
import android.opengl.GLSurfaceView;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.util.Log;

public class DrawActivity extends AppCompatActivity {
    private final int CONTEXT_CLIENT_VERSION = 3;
    private GLSurfaceView mGLSurfaceView;
    RendererJNI mRenderer;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        // 从 Intent 中获取传递过来的参数
        String action = getIntent().getStringExtra("Action"); // 这里的 "key" 必须和 ActivityA 中的键名保持一致
        // 根据需要使用参数的值进行操作，这里只是简单地设置到 TextView 中显示出来

        mGLSurfaceView = new GLSurfaceView(this);
        mRenderer=new RendererJNI(this, action);
        if (detectOpenGLES30()) {
            // 设置OpenGl ES的版本
            mGLSurfaceView.setEGLContextClientVersion(CONTEXT_CLIENT_VERSION);
            // 设置与当前GLSurfaceView绑定的Renderer
            mGLSurfaceView.setRenderer(mRenderer);
            // 设置渲染的模式
//            mGLSurfaceView.setRenderMode(RENDERMODE_WHEN_DIRTY);
            mGLSurfaceView.setRenderMode(RENDERMODE_CONTINUOUSLY);
        } else {
            Log.e("opengles30", "OpenGL ES 3.0 not supported on device.  Exiting...");
            finish();
        }

        setContentView(mGLSurfaceView);
    }

    @Override
    protected void onResume() {
        super.onResume();
        mGLSurfaceView.onResume();
    }

    @Override
    protected void onPause() {
        super.onPause();
        mGLSurfaceView.onPause();
    }

    private boolean detectOpenGLES30() {
        ActivityManager am = (ActivityManager)getSystemService(Context.ACTIVITY_SERVICE);
        ConfigurationInfo info = am.getDeviceConfigurationInfo();

        return (info.reqGlEsVersion >= 0x30000);
    }
}
