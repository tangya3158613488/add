package tomcat;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.net.ServerSocket;
import java.net.Socket;

import javax.activation.UnsupportedDataTypeException;
public class Server {
	ServerSocket ser;
	public Server()
	{
		try{
			ser = new ServerSocket(8080);
			System.out.println("tomcat开始启动");
			System.out.println("消耗了0.01ms");
		}catch(IOException e){
			e.printStackTrace();
		}
	}
	public void start()
	{
		try {
			Socket client = ser.accept();
			InputStream is = client.getInputStream();
			InputStreamReader isr = new InputStreamReader(is,"ISO-8859-1");
			BufferedReader br = new BufferedReader(isr);
			String str = "";
			while(!(str = br.readLine()).equals("")){
				System.out.println(str);
			}
			//处理请求                                                       
            OutputStream os=client.getOutputStream();                    
            //把项目根目录下webapps下的文件发给浏览器
            File file=new File("webapps/index.html");                                
            os.write("HTTP/1.1 200 OK".getBytes("ISO-8859-1"));                                 
            os.write("\r\n".getBytes("ISO-8859-1"));                                            
            os.write(("Content-Length: "+file.length()).getBytes("ISO-8859-1"));                 
            os.write("\r\n".getBytes("ISO-8859-1"));                                            
            os.write("Content-Type: text/html;charset=utf-8".getBytes("ISO-8859-1"));         
            os.write("\r\n".getBytes("ISO-8859-1"));                                            
            os.write("\r\n".getBytes("ISO-8859-1")); 
            FileInputStream fis=new FileInputStream(file);
            byte[] b=new byte[(int)file.length()];
            fis.read(b);
            os.write(b);                                               
            os.flush();                                                  
            os.close();    
		} catch (UnsupportedDataTypeException e) {
			e.printStackTrace();
		}catch (IOException e) {
			e.printStackTrace();
		}
	}
	public static void main(String[] args){
		new Server().start();
	}
}
