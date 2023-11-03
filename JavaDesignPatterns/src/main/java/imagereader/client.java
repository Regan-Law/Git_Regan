package imagereader;

public class client{
    public static void main(String[] args){
        ImageReaderFactory factory=new ImageReaderFactory();

        ImageReader gifReader=factory.createImageReader("GIF");
        gifReader.readImage();

        ImageReader jpgReader=factory.createImageReader("JPG");
        jpgReader.readImage();
    }
}