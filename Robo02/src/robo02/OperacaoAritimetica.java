package robo02;
import java.time.Instant;
import java.time.LocalDate;
import  java.util.Date;
import java.util.Calendar;

/**
 *
 * @author Flávio
 */
public class OperacaoAritimetica extends Robo{
    double numero1;
    double numero2;
    int decremento=1;

    public OperacaoAritimetica(String nome) {
        super(nome, Date.from(Instant.now()),"C:\\java");
        this.numero1 = 0;
        this.numero2 = 0;
    }
    
    public OperacaoAritimetica(double numero1, double numero2, String nome, int bateria) {
        super(nome, Date.from(Instant.now()),"C:\\java");
        this.numero1 = numero1;
        this.numero2 = numero2;
    }
    
    public OperacaoAritimetica(double numero1, double numero2) {
        super("James",Date.from(Instant.now()),"C:\\java");
        this.numero1 = numero1;
        this.numero2 = numero2;
    }

    public double getNumero1() {
        return numero1;
    }

    public void setNumero1(double numero1) {
        this.numero1 = numero1;
    }

    public double getNumero2() {
        return numero2;
    }

    public void setNumero2(double numero2) {
        this.numero2 = numero2;
    }

    public void setDecremento(int decremento) {
        this.decremento = decremento;
    }

    public double operação(int n){
        double resultado;
        switch(n){
            case 1:
                resultado = numero1 + numero2;//soma
            case 2:
                resultado =  numero1 - numero2;//subtração
            case 3:
                resultado =  numero1 * numero2; //Multiplicação
            case 4:
                resultado =  numero1 / numero2;//Divisão  
            default:
                resultado =  0;//Sem operação
        }
        decrementaBateria(decremento);
        return resultado;
    }
}
