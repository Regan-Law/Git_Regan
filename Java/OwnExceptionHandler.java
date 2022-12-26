class OwnException extends Exception {
    int i;
    public OwnException(String msg) {
        super(msg);
    }
}

class OwnExceptionSource {
    void a() throws OwnException {
        throw new OwnException("error");
    }
}

public class OwnExceptionHandler {

    public static void main(String[] args) {
        OwnExceptionSource er=new OwnExceptionSource();
        try {
            er.a();
        } catch(OwnException e) {
            e.printStackTrace();
            System.out.println("error");
        } finally {
            System.out.println("over");
        }
    }
}