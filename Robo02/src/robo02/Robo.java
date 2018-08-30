package robo02;
import java.util.Date;
import java.io.File;
import javax.swing.JOptionPane;
import java.io.BufferedReader;
import java.io.PrintStream;
import java.io.FileWriter;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
/**
 * @author Flávio
 */
public class Robo {
    private String nome;
    private Date dataFab;
    private int bateria;
    String caminhoArquivoBateria;

    public Robo(String Nome, Date dataFab, String caminhoArquivoBateria) {
        this.nome = Nome;
        this.dataFab = dataFab;
        this.caminhoArquivoBateria = caminhoArquivoBateria;
        this.bateria = lerBateria();
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public Date getDataFab() {
        return dataFab;
    }

    public void setDataFab(Date dataFab) {
        this.dataFab = dataFab;
    }

    public int getBateria() {
        return bateria;
        
    }

    public void setBateria(int bateria) {
        this.bateria = bateria;
    }
    
    public int lerBateria(){ //O arquivo terá o nome do robo
        String file = this.nome+".txt"; 
       File arquivo = new File(caminhoArquivoBateria,file);
       //File arquivo = new File ("/java/novo.txt");
        if(arquivo.exists()){
            try {
              FileReader arq = new FileReader(arquivo);
              BufferedReader lerArq = new BufferedReader(arq);
              String linha = lerArq.readLine();
              lerArq.close();
                System.out.println("Lendo arquivo...");
              return Integer.valueOf(linha);
            }catch(Exception e){
                JOptionPane.showMessageDialog(null, "Desculpa, mas ocorreu um erro ao tentar ler a bateria >.<");
                return 0;
            } 
            
        }else{//Caso o arquivo não exista ainda, cria um novo arquivo
            try{
                System.out.println("Criando arquivo "+this.nome+".txt");
            FileWriter arq = new FileWriter(arquivo);
            PrintWriter gravarArq = new PrintWriter(arq);
            setBateria(10);
            gravarBateria();
             System.out.println("Arquivo "+this.nome+".txt Criado com sucesso");
            return this.bateria;
            }
            catch(Exception f){
                JOptionPane.showMessageDialog(null, "Não foi possível criar o arquivo");
                return 0;
            }
        }
    }
    public void gravarBateria(){
        String file = this.nome+".txt";
        File arquivo = new File(caminhoArquivoBateria,file);
        if(arquivo.exists()){
            try {
                FileWriter arq = new FileWriter(arquivo);
                PrintWriter gravarArq = new PrintWriter(arq);
                gravarArq.printf("%d",this.bateria);
                gravarArq.close();
                JOptionPane.showMessageDialog(null, this.nome+"\nGravação realizada!\nBateria : "+ lerBateria());
            }catch(Exception e){
                JOptionPane.showMessageDialog(null, "Desculp!\nOcorreu uma falha ao tentar armazenar a bateria>.<");
            } 
        }
    }
   public void decrementaBateria(int i){
       this.bateria -=i;
   }
   public void salvaBateria(){
       
   }
   public void recarregar(int i){
       setBateria(i);
       gravarBateria();
   }
}
