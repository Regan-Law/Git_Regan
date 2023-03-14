package com.itcast.listview;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseAdapter;
import android.widget.ImageView;
import android.widget.ListView;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {
    private ListView mListView;
    private String[] titles={"桌子","苹果","蛋糕","线衣","猕猴桃","围巾",};
    private String[] prices={"1800元","10元/kg","300元","350元","10元/kg","280元"};
    private int[] icons={R.mipmap.table,R.mipmap.apple,R.mipmap.cake,R.mipmap.wireclothes,R.mipmap.kiwifruit,R.mipmap.scarf};
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        mListView=findViewById(R.id.lv);
        MyBaseAdapter mAdapter=new MyBaseAdapter();
        mListView.setAdapter(mAdapter);
    }
    class MyBaseAdapter extends BaseAdapter{
        public int getCount() {
            return titles.length;
        }
        public Object getItem(int position) {
            return titles[position];
        }
        public long getItemId(int position) {
            return position;
        }
        class ViewHolder{
            TextView title;
            TextView price;
            ImageView iv;
        }

        public View getView(int position, View convertView, ViewGroup parent) {
            ViewHolder holder;
            if(convertView==null){
                convertView=View.inflate(MainActivity.this,R.layout.list_item,null);
                holder=new ViewHolder();
                holder.title=convertView.findViewById(R.id.title);
                holder.price=convertView.findViewById(R.id.price);
                holder.iv=convertView.findViewById(R.id.iv);
                convertView.setTag(holder);
            }else{
                holder=(ViewHolder)convertView.getTag();
            }
            holder.title.setText(titles[position]);
            holder.price.setText(prices[position]);
            holder.iv.setImageResource(icons[position]);
            return convertView;
        }

    }
}
