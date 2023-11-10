package homework3.arraystrategy;

public class ArrayOperation{
    private SortStrategy sortStrategy;

    public void setSortStrategy(SortStrategy sortStrategy){
        this.sortStrategy=sortStrategy;
    }

    public int[] sort(int[] arr){
        sortStrategy.sort(arr);
        return arr;
    }
}