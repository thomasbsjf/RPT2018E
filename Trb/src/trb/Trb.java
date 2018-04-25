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
public class Trb {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args)  {
        Menu m = new Menu();
        Questions []Q;
        Q = new Questions[10];
        m.criaVetorQuestions(10, Q);
        m.cenario1(10);
    for(int n=0;n<10;n++)
{
    Q[n].imprime();
}
    }
}

