package homework3.arraystrategy;

import java.util.Arrays;

public class Client{
    public static void main(String[] args){
        int[] arr1={5,8,67,6,3,4};
        int[] arr2={5,8,34,6,3,4};
        int[] arr3={5,8,1,6,3,4};
        //生成一个策略环境类
        ArrayOperation handlerSort=new ArrayOperation();

        //生成策略
        SortStrategy sort1, sort2, sort3;
        sort1=new BubbleSort();
        sort2=new SelectionSort();
        sort3=new InsertionSort();

        //冒泡排序
        handlerSort.setSortStrategy(sort1);
        System.out.println("排序前："+Arrays.toString(arr1));
        handlerSort.sort(arr1);
        System.out.println("排序后："+Arrays.toString(arr1));

        //选择排序
        handlerSort.setSortStrategy(sort2);
        System.out.println("排序前："+Arrays.toString(arr2));
        handlerSort.sort(arr2);
        System.out.println("排序后："+Arrays.toString(arr2));

        //插入排序
        handlerSort.setSortStrategy(sort3);
        System.out.println("排序前："+Arrays.toString(arr3));
        handlerSort.sort(arr3);
        System.out.println("排序后："+Arrays.toString(arr3));
    }
}