package revisao;

import java.util.ArrayList;
import java.util.Scanner;

public class Turma {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		ArrayList<Estudante> classe = new ArrayList<Estudante>();
		short option = 1;
		Scanner sc = new Scanner(System.in);
		do {
			System.out.println("Escolha uma ação:\n1-Cadastrar Aluno\n2-Remover Aluno\n3-Buscar Aluno\n4-Exibir informações sobre todos os alunos");
			option = sc.nextShort();
			String matricula, nome;
			short idade;
			switch(option){
				case 1:
					System.out.println("Digite o nome do estudante:");
					sc.nextLine();
					nome = sc.nextLine();
					System.out.println("Digite a idade do estudante:");
					idade = sc.nextShort();
					System.out.println("Digite a matricula do estudante:");
					sc.nextLine();
					matricula = sc.nextLine();
					Estudante e = new Estudante(nome, idade, matricula);
					classe.add(e);
					break;
				case 2:
					System.out.println("Digite o número da matricula do aluno que deseja remover:");
					sc.nextLine();
					matricula = sc.nextLine();
					for(Estudante es: classe) {
						if(es.getMatricula().equals(matricula)) {
							classe.remove(classe.indexOf(es));
						}
					}
					break;
				case 3:
					System.out.println("Digite o número da matricula do aluno que deseja buscar:");
					sc.nextLine();
					matricula = sc.nextLine();
					for(Estudante es: classe) {
						if(es.getMatricula().equals(matricula)) {
							System.out.println(es);
						}
					}
					break;
				case 4:
					for(Estudante es: classe) {						
						System.out.println(es);
					}
					break;
			}
		}while(option != 0);
		sc.close();
	}

}
