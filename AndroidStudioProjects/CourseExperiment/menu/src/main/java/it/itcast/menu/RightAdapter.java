package it.itcast.menu;

import android.content.Context;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseAdapter;
import android.widget.ImageView;
import android.widget.TextView;

import java.util.List;

public class RightAdapter extends BaseAdapter {
    private Context mcontext;
    private List<FoodBean> list;

    public RightAdapter(Context context, List<FoodBean> list) {
        this.mcontext = context;
        this.list = list;
    }

    @Override
    public int getCount() {
        return list.size();
    }

    @Override
    public Object getItem(int position) {
        return list.get(position);
    }

    @Override
    public long getItemId(int position) {
        return position;
    }

    @Override
    public View getView(int position, View convertView, ViewGroup parent) {
        ViewHolder holder = null;
        if (convertView == null) {
            convertView = View.inflate(mcontext, R.layout.list_item, null);
            holder = new ViewHolder();
            holder.iv_img = convertView.findViewById(R.id.iv_img);
            holder.tv_name = convertView.findViewById(R.id.tv_name);
            holder.tv_price = convertView.findViewById(R.id.tv_price);
            holder.tv_sale = convertView.findViewById(R.id.tv_sale);
            convertView.setTag(holder);
        } else {
            holder = (ViewHolder) convertView.getTag();
        }
        FoodBean foodBean = list.get(position);
        holder.iv_img.setImageResource(foodBean.getImg());
        holder.tv_name.setText(foodBean.getName());
        holder.tv_price.setText(foodBean.getPrice());
        holder.tv_sale.setText(foodBean.getSales());
        return convertView;
    }

    class ViewHolder {
        ImageView iv_img;
        TextView tv_name;
        TextView tv_price;
        TextView tv_sale;
    }
}
