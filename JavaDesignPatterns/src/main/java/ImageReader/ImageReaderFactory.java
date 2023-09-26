package ImageReader;

public class ImageReaderFactory{
    public ImageReader createImageReader(String imageType){
        if(imageType.equalsIgnoreCase("GIF")){
            return new GifReader();
        }else if(imageType.equalsIgnoreCase("JPG")){
            return new JpgReader();
        }else{
            throw new IllegalArgumentException("Unknown type");
        }
    }
}