package ComputerFacade;

public class MainFrame{
    private Memory meomory;
    private Cpu cpu;
    private HardDisk hardDisk;
    private Os os;

    public MainFrame(){
        meomory=new Memory();
        cpu=new Cpu();
        hardDisk=new HardDisk();
        os=new Os();
    }

    public void start(){
        meomory.check();
        cpu.run();
        hardDisk.read();
        os.load();
    }
}