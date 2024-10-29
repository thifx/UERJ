package revisao;

public class Estudante {
	private String nome;
	private short idade;
	private String matricula;
	
	public Estudante(String nome, short idade, String matricula) {
		this.nome = nome;
		this.idade = idade;
		this.matricula = matricula;
	}
	public String getMatricula() {
		return matricula;
	}
	public void setMatricula(String matricula) {
		this.matricula = matricula;
	}
	public short getIdade() {
		return idade;
	}
	public void setIdade(short idade) {
		this.idade = idade;
	}
	public String getNome() {
		return nome;
	}
	public void setNome(String nome) {
		this.nome = nome;
	}

	@Override
	public String toString() {
		return "Estudante [nome=" + nome + ", idade=" + idade + ", matricula=" + matricula + "]";
	}
}
