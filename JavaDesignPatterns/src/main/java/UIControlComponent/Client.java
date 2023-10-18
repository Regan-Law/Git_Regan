package UIControlComponent;

public class Client{
    public static void main(String[] args){
        Component button, textBox, window, panel;
        window=new Container("窗体");
        panel=new Container("中间面板");
        button=new Button("按钮");
        textBox=new TextBox("文本框");
        panel.add(button);
        panel.add(textBox);
        window.add(panel);
        window.display();
    }
}