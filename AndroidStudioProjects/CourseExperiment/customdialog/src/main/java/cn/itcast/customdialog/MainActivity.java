package cn.itcast.customdialog;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.widget.Button;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        init();
    }
    private void init() {
        Button btn_dialog = findViewById(R.id.btn_dialog);
        btn_dialog.setOnClickListener(v -> {
            CommonDialog dialog = new CommonDialog(this);
            dialog.setTitle("提示");
            dialog.setMessage("您确定要删除信息：");
            dialog.setPositive("确定");
            dialog.setNegative("取消");
            dialog.setOnClickBottomListener(new CommonDialog.OnClickBottomListener() {
                @Override
                public void onPositiveClick() {
                    dialog.dismiss();
                }
                @Override
                public void onNegativeClick() {
                    dialog.dismiss();
                }
            });
            dialog.show();
        });
    }
}