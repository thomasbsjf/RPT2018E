package arvoreavl;

public class AVL {
    
    public int Altura(No p){
        Integer alturaEsq, alturaDir;
        if(p==null) return 0;
        else{
            alturaEsq = Altura(p.getAnterior());
            alturaDir = Altura(p.getProximo());
            if(alturaEsq >alturaDir){
                return (1+ alturaEsq);
            }else{
                return (1+ alturaDir);
            }
        }
    }
    
    public int Calcula_FB(No p){
        if(p==null) return 0;
        return (Altura(p.getAnterior()) - Altura(p.getProximo()));
    }
    
    public void Set_FB(No p){
        if(p!=null){
            p.setMarca(Altura(p.getAnterior()) - Altura(p.getProximo()));
            Set_FB(p.getAnterior());
            Set_FB(p.getProximo());
        }
    }
}
