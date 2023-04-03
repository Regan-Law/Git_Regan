package it.itcast.menu;

import android.graphics.Color;
import android.os.Bundle;
import android.widget.TextView;

import androidx.appcompat.app.AppCompatActivity;
import androidx.fragment.app.FragmentManager;
import androidx.fragment.app.FragmentTransaction;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class MainActivity extends AppCompatActivity {
    private FragmentManager fragmentManager;
    private FragmentTransaction fragmentTransaction;
    private LeftFragment leftFragment;
    private RightFragment rightFragment;
    private TextView tv_recommend, tv_must_buy;
    private String[] names1 = {"爆款*肥牛鱼豆腐骨肉相连三荤五素一份米饭", "豪华双人套餐", "【热销】双人套餐（含两份米饭）"};
    private String[] sales1 = {"月售 520 好评度 80%", "月售 184 好评 68%", "月售 114 好评 60%"};
    private String[] prices1 = {"￥23", "￥41", "￥32"};
    private int[] imgs1 = {R.mipmap.recom_one, R.mipmap.recom_two, R.mipmap.recom_three};
    private String[] names2 = {"蔬菜主义1人套餐", "2人经典套餐", "3人经典套餐"};
    private String[] sales2 = {"月售 26 好评度 70%", "月售 12 好评 50%", "月售 4 好评 75%"};
    private String[] prices2 = {"￥44", "￥136", "￥108"};
    private int[] imgs2 = {R.mipmap.must_buy_one, R.mipmap.must_buy_two, R.mipmap.must_buy_three};
    private Map<String, List<FoodBean>> map;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        setData();
        init();
        clickEvent();
    }

    private void init() {
        fragmentManager = getSupportFragmentManager();
        leftFragment = (LeftFragment) fragmentManager.findFragmentById(R.id.left);
        tv_recommend = leftFragment.getView().findViewById(R.id.tv_recommend);
        tv_must_buy = leftFragment.getView().findViewById(R.id.tv_must_buy);
    }

    private void setData() {
        map = new HashMap<>();
        List<FoodBean> list1 = new ArrayList<>();
        List<FoodBean> list2 = new ArrayList<>();
        for (int i = 0; i < names1.length; i++) {
            FoodBean foodBean = new FoodBean();
            foodBean.setName(names1[i]);
            foodBean.setSales(sales1[i]);
            foodBean.setPrice(prices1[i]);
            foodBean.setImg(imgs1[i]);
            list1.add(foodBean);
        }
        map.put("1", list1);
        for (int i = 0; i < names2.length; i++) {
            FoodBean foodBean = new FoodBean();
            foodBean.setName(names2[i]);
            foodBean.setSales(sales2[i]);
            foodBean.setPrice(prices2[i]);
            foodBean.setImg(imgs2[i]);
            list2.add(foodBean);
        }
        map.put("2", list2);
    }

    private void clickEvent() {
        tv_recommend.setOnClickListener(v -> {
            switchData(map.get("1"));
            tv_recommend.setBackgroundColor(Color.WHITE);
            tv_must_buy.setBackgroundResource(R.color.gray);
        });
        tv_must_buy.setOnClickListener(v -> {
            switchData(map.get("2"));
            tv_must_buy.setBackgroundColor(Color.WHITE);
            tv_recommend.setBackgroundResource(R.color.gray);
        });
        switchData(map.get("1"));
    }

    public void switchData(List<FoodBean> list) {
        fragmentManager = getSupportFragmentManager();
        fragmentTransaction = fragmentManager.beginTransaction();
        rightFragment = new RightFragment().getInstance(list);
        fragmentTransaction.replace(R.id.right, rightFragment);
        fragmentTransaction.commit();
    }
}