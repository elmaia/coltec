package org.teiacoltec.poo;

import java.util.List;

import org.teiacoltec.poo.aluno.Aluno;
import org.teiacoltec.poo.alunoDAO.AlunoDAO;
import org.teiacoltec.poo.alunoDAO.AlunoExistenteException;
import org.teiacoltec.poo.alunoDAO.AlunoNaoEncontradoException;
import org.teiacoltec.poo.conexao.FalhaConexaoException;

class AlunoDAOTest {

    /**
     * Testa a inserção de um aluno.
     */
    static void testaInsere() {
        try {
            // Cria um aluno e persiste
            Aluno aluno = new Aluno(2024950102, "Leandro Maia", java.sql.Date.valueOf("1985-08-08"), "leandro@teiacoltec.org", "Computacao");
            AlunoDAO.insere(aluno);

            // Tenta recuperar o aluno recém criado
            Aluno alunoRecuperado = AlunoDAO.obtemAlunoPorMatricula(2024950102);

            // Mostra as informações dos dois para serem comparadas
            System.out.println(aluno);
            System.out.println(alunoRecuperado);
        } catch (AlunoExistenteException | FalhaConexaoException | AlunoNaoEncontradoException e) {
            System.err.println("Excecao: " + e.getMessage());
        }
    }

    /**
     * Testa a atualização de um aluno.
     */
    static void testaAtualiza() {
        try {
            // Cria um aluno e persiste
            Aluno aluno = new Aluno(2024950102, "Leandro Maia", java.sql.Date.valueOf("1985-08-08"), "leandro@teiacoltec.org", "Computacao");
            AlunoDAO.insere(aluno);

            // Altera dados e persiste
            aluno.setNome("Leandro Maia Silva");
            AlunoDAO.atualiza(aluno);

            // Tenta recuperar o aluno recém atualizado
            Aluno alunoRecuperado = AlunoDAO.obtemAlunoPorMatricula(2024950102);

            // Mostra as informações dos dois para serem comparadas
            System.out.println(aluno);
            System.out.println(alunoRecuperado);
        } catch (AlunoExistenteException | FalhaConexaoException | AlunoNaoEncontradoException e) {
            System.err.println("Excecao: " + e.getMessage());
        }
    }

    /**
     * Testa a remoção de um aluno.
     */
    static void testaRemove() {
        try {
            // Cria um aluno e persiste
            Aluno aluno = new Aluno(2024950102, "Leandro Maia", java.sql.Date.valueOf("1985-08-08"), "leandro@teiacoltec.org", "Computacao");
            AlunoDAO.insere(aluno);

            // Tenta remover
            AlunoDAO.remove(aluno);
        } catch (AlunoExistenteException | AlunoNaoEncontradoException | FalhaConexaoException e) {
            System.err.println("Excecao: " + e.getMessage());
        }
    }

    /**
     * Testa a obtenção de um aluno por matrícula.
     */
    static void testaObtemAlunoPorMatricula() {
        try {
            // Cria um aluno e persiste
            Aluno aluno = new Aluno(2024950102, "Leandro Maia", java.sql.Date.valueOf("1985-08-08"), "leandro@teiacoltec.org", "Computacao");
            AlunoDAO.insere(aluno);

            // Tenta recuperar o aluno recém atualizado
            Aluno alunoRecuperado = AlunoDAO.obtemAlunoPorMatricula(2024950102);

            // Mostra as informações dos dois para serem comparadas
            System.out.println(aluno);
            System.out.println(alunoRecuperado);
        } catch (AlunoExistenteException | FalhaConexaoException | AlunoNaoEncontradoException e) {
            System.err.println("Excecao: " + e.getMessage());
        }
    }

    /**
     * Testa a obtenção da lista de alunos.
     */
    static void testaObtemListaAlunos() {
        try {
            // Cria alunos e persiste
            Aluno aluno1 = new Aluno(2024950102, "Leandro Maia", java.sql.Date.valueOf("1985-08-08"), "leandro@teiacoltec.org", "Computacao");
            Aluno aluno2 = new Aluno(2024950203, "Maria Souza",  java.sql.Date.valueOf("1999-05-10"), "maria@gmail.com", "Engenharia");
            AlunoDAO.insere(aluno1);
            AlunoDAO.insere(aluno2);

            // Obtem a lista de alunos
            List<Aluno> listaAlunos = AlunoDAO.obtemListaAlunos();

            // Exibe a lista de alunos
            System.out.println("Lista de Alunos: ");
            for(Aluno aluno : listaAlunos) {
                System.out.println(aluno);
            }

        } catch (AlunoExistenteException | FalhaConexaoException e) {
            System.err.println("Excecao: " + e.getMessage());
        }
    }

    /**
     * Testa a exceção AlunoNaoEncontradoException.
     */
    static void testaAlunoNaoEncontradoException() {
        try {
            AlunoDAO.obtemAlunoPorMatricula(999);
         } catch (FalhaConexaoException | AlunoNaoEncontradoException e) {
            System.err.println("Excecao: " + e.getMessage());
        }
   }
}