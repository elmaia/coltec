package org.teiacoltec.poo.alunoDAO;

public class AlunoNaoEncontradoException extends Exception {

    public AlunoNaoEncontradoException(int matricula) {
        super("Aluno de matricula " + matricula + " nao encontrado.");
    }


}