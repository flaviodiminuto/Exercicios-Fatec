package robo02;

/**
 *
 * @author Flávio
 */
public class Robo02 {


    public static void main(String[] args) {
        // TODO code application logic here
        OperacaoAritimetica r1 = new OperacaoAritimetica(1,2);
        OperacaoAritimetica r2 = new OperacaoAritimetica("Jorginho");
        
        r1.decrementaBateria(2);
        r1.recarregar(r1.lerBateria() +3);
        
        r2.setNumero1(10);
        r2.setNumero2(5);
        r2.operação(1);
        r2.gravarBateria();
    }
    
}
