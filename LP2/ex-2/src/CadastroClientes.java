import java.util.ArrayList;
import java.util.Scanner;

public class CadastroClientes {
    public static void main(String[] args) {
        ArrayList<Cliente> clientes = new ArrayList<Cliente>();
        int option = 0;
        Scanner sc = new Scanner(System.in);
        while (option != 4) {
            System.out.println("1- Cadastrar cliente\n2- Buscar cliente pelo nome\n3- Exibir dados dos clientes\n4- Sair");
            option = sc.nextInt();
            sc.nextLine();
            switch (option) {
                case 1:
                    System.out.println("Insira o nome do cliente:");
                    String nome = sc.nextLine();
                    System.out.println("Insira o cpf do cliente:");
                    String cpf = sc.nextLine();
                    System.out.println("Insira o telefone do cliente:");
                    String telefone = sc.nextLine();
                    Cliente c = new Cliente(clientes.size() + 1, nome, cpf, telefone);
                    clientes.add(c);
                    break;
                case 2:
                    if(clientes.isEmpty()) {
                        System.out.println("Não existe nenhum cliente na lista");
                        continue;
                    }
                    System.out.println("Insira o nome do cliente:");
                    String nomeParaProcurar = sc.nextLine();
                    for(Cliente client: clientes){
                        if(client.getNome().equals(nomeParaProcurar)){
                            System.out.println(client);
                        }
                    }
                    break;
                case 3:
                    if(clientes.isEmpty()) {
                        System.out.println("Não existe nenhum cliente na lista");
                        break;
                    }
                    for(Cliente client: clientes){ System.out.println(client);}
                    break;
                default:
                    break;
            }
        }
        sc.close();
    }
}