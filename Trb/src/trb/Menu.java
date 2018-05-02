package trb;
import java.io.FileReader;
import java.io.IOException;
import java.util.Scanner;
        
public class Menu {
    int menu()
    {
        System.out.println("\n Digite o cenario desejado numerados de 1 a 4 \n");
        int x=0;
        Scanner scan=new Scanner(System.in);

        System.out.println("CENARIO 1 : Impacto de diferentes estruturas de dados.\\n CENARIO 2 : Impactos da variação de QuickSort \\n CENARIO 3 : Quicksort X InsertionSort X Mergesort X Heapsort X Meusort \\n CENARIO 4 Tratamento de Colisões: Endereçamento X Encadeamento \\n\"");
        while(x<1||x>4)
        {
            x=scan.nextInt();
            if(x==1)
            {
                System.out.println("\"\\n Valor digitado INVALIDO, digite novamente um valor valido entre 1 e 4.\"");
            }    
        }
        return x;
    }

    void cenario1(int n)
    {
      Questions []Q=new Questions[n];
      criaVetorQuestions(n,Q);
      Integer []v=new Integer [n];
      for(int i=0;i<n;i++)
      { 
          System.out.println(Q[i].id);
      }
      for(int i=0;i<n;i++)
            System.out.println(v[i]);

    }
    void criaVetorQuestions(int N,Questions[] Q)  
    {   
        try(FileReader f=new FileReader("Questions.txt"))
        {
        Scanner questions= new Scanner(f);
        int i=0;
        Questions q ;
        String user,data,score,title;
        String id;
        int x=0;
        try
        {
            while(questions.hasNext())
            {
                id=questions.nextLine();
                user=questions.nextLine();
                data=questions.nextLine();
                score=questions.nextLine();
                title=questions.nextLine();
                Q[i]=new Questions(id,user,data,score,title);
                i++;
            }
        }
            catch (Exception e)
            {
                
            }


        }catch (IOException ex)
        {
            ex.printStackTrace();
        }
    }
}



