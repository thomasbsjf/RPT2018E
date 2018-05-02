package trb;

public class Questions {
    String id;
    String user,data,score,title;

    public Questions(String id, String user, String data, String score, String title) {
        this.id = id;
        this.user = user;
        this.data = data;
        this.score = score;
        this.title = title;
    }
    
   void imprime()
   {
        System.out.println("id "+id);
        System.out.println("usr " +user);
        System.out.println("data " +data);
        System.out.println("score "+score);
        System.out.println("title "+title);
   }
}
