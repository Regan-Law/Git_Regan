package cn.itcast.customdialog;
import android.app.AlertDialog;
import android.content.Context;
import android.os.Bundle;
import android.text.TextUtils;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

public class CommonDialog extends AlertDialog{
    private TextView titleTv;
    private TextView messageTv;
    private Button negativeBtn,positiveBtn;
    public CommonDialog(Context context) {
        super(context);
    }
    private String message;
    private String title;
    private String positive,negative;
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.custom_dialog);
        initView();
        initEvent();
    }
    private void initView() {
        titleTv = findViewById(R.id.title);
        messageTv = findViewById(R.id.message);
        negativeBtn = findViewById(R.id.negative);
        positiveBtn = findViewById(R.id.positive);
    }
    private void refreshView() {
        if(!TextUtils.isEmpty(title)) {
            titleTv.setText(title);
            titleTv.setVisibility(View.VISIBLE);
        }else {
            titleTv.setVisibility(View.GONE);
        }
        if(!TextUtils.isEmpty(message)) {
            messageTv.setText(message);
        }
        if(!TextUtils.isEmpty(positive)) {
            positiveBtn.setText(positive);
        }else {
            positiveBtn.setText("确定");
        }
        if(!TextUtils.isEmpty(negative)) {
            negativeBtn.setText(negative);
        }else {
            negativeBtn.setText("取消");
        }
    }
    private void initEvent() {
        positiveBtn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if(onClickBottomListener != null) {
                    onClickBottomListener.onPositiveClick();
                }
            }
        });
        negativeBtn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if(onClickBottomListener != null) {
                    onClickBottomListener.onNegativeClick();
                }
            }
        });
    }
    public void show() {
        super.show();
        refreshView();
    }
    public interface OnClickBottomListener{
        void onPositiveClick();
        void onNegativeClick();
    }
    public CommonDialog.OnClickBottomListener onClickBottomListener;
    public CommonDialog setOnClickBottomListener(OnClickBottomListener onClickBottomListener) {
        this.onClickBottomListener = onClickBottomListener;
        return this;
    }
    public CommonDialog setMessage(String message) {
        this.message = message;
        return this;
    }
    public CommonDialog setTitle(String title) {
        this.title = title;
        return this;
    }
    public CommonDialog setPositive(String positive) {
        this.positive = positive;
        return this;
    }
    public CommonDialog setNegative(String negative) {
        this.negative = negative;
        return this;
    }
}
