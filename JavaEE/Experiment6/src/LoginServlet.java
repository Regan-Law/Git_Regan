import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.IOException;
import java.io.PrintWriter;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

public class LoginServlet extends HttpServlet{
    @Override
    protected void doGet(HttpServletRequest request,HttpServletResponse response) throws ServletException, IOException{
        doPost(request,response);
    }

    @Override
    protected void doPost(HttpServletRequest request,HttpServletResponse response) throws IOException{
        response.setContentType("text/html;charset=utf-8");
        request.setCharacterEncoding("utf-8");
        PrintWriter out=response.getWriter();
        String username=request.getParameter("username");
        String password=request.getParameter("password");
        if(username==null||username.length()==0){
            out.println("<script>");
            out.println("alert('请输入用户名！');");
            out.println("window.location.href='login.jsp';");
            out.println("</script>");
        }else if(password==null||password.length()==0){
            out.println("<script>");
            out.println("alert('请输入密码！');");
            out.println("window.location.href='login.jsp';");
            out.println("</script>");
        }else{
            try{
                Connection conn=DataBaseConnection.get();
                String sql="select username,password from user where username=? and password=?";
                PreparedStatement stmt=conn.prepareStatement(sql);
                stmt.setString(1,username);
                stmt.setString(2,password);
                ResultSet rs=stmt.executeQuery();
                if(rs.next()){
                    HttpSession session=request.getSession();
                    session.setAttribute("username",username);
                    response.sendRedirect("loginsuccess.jsp");
                }else{
                    out.println("<script>");
                    out.println("alert('用户名或密码错误！');");
                    out.println("window.location.href='login.jsp';");
                    out.println("</script>");
                }
                rs.close();
                stmt.close();
                conn.close();
            }catch(SQLException e){
                throw new RuntimeException(e);
            }
        }
    }
}