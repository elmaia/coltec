package org.teiacoltec.poo.alunoDAO;

public class AlunoExistenteException extends Exception {

    public AlunoExistenteException(int matricula) {
        super("Aluno com matricula " + matricula + " ja existente no banco de dados.");
    }
}