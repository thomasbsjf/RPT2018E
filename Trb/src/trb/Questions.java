/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package trb;

/**
 *
 * @author ice
 */
public class Questions {
 String id;
 String user,data,score,title;
  Questions(String id1, String user1,String data1,String score1,String title1)
{
    id = id1;
    user = user1;
    data = data1;
    score = score1;
    title = title1;
}
void  imprime()
{
    System.out.println("id "+id);
    System.out.println("usr " +user);
     System.out.println("data " +data);
         System.out.println("score "+score);
    System.out.println("title "+title);
}
}
