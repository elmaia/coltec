package org.teiacoltec.poo.alunoDAO;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.List;

import org.teiacoltec.poo.aluno.Aluno;
import org.teiacoltec.poo.conexao.Conexao;
import org.teiacoltec.poo.conexao.FalhaConexaoException;

public class AlunoDAO {

    private static final int MATRICULA_POSICAO_TABELA = 1;
    private static final int NOME_POSICAO_TABELA = 2;
    private static final int NASCIMENTO_POSICAO_TABELA = 3;
    private static final int EMAIL_POSICAO_TABELA = 4;
    private static final int CURSO_POSICAO_TABELA = 5;

    /* Códigos de erro */
    static final int DUPLICATE_KEY_ERROR_CODE = 1062;    

    /**
     * Cria a tabela de alunos caso ela não exista.
     * @throws FalhaConexaoException Falha ao obter conexão com o SGBD.
     */
    public static void criaTabelaAluno() throws  FalhaConexaoException {

        try {
            // Estabelecer conexao
            Connection conexao = Conexao.obtemConexao();

            // Faço a consulta
            Statement stmt = conexao.createStatement();
            stmt.execute("CREATE TABLE IF NOT EXISTS alunos (matricula INT PRIMARY KEY," +
                                                            "nome VARCHAR(255) NOT NULL," +
                                                            "data_nascimento DATE NOT NULL," +
                                                            "email VARCHAR(255) NOT NULL," +
                                                            "curso VARCHAR(255) NOT NULL);");
        } catch (SQLException e) {
            throw new Error(e.getMessage());
        }    
    }

    /**
     * Obtem um aluno a partir do seu número de matrícula.
     * @param matricula Matrícula do aluno.
     * @return Aluno com o número de matrícula especificado.
     * @throws AlunoNaoEncontradoException Não foi encontrado aluno com a matrícula especificada.
     * @throws FalhaConexaoException Falha ao obter conexão com o SGBD.
     */
    public static Aluno obtemAlunoPorMatricula(int matricula) throws AlunoNaoEncontradoException, FalhaConexaoException {

        try {
            // Estabelecer conexao
            Connection conexao = Conexao.obtemConexao();

            // Faço a consulta
            Statement stmt = conexao.createStatement();
            ResultSet resultado = stmt.executeQuery("SELECT * from alunos WHERE matricula = " + matricula + ";");

            if (resultado.next()) {
                // Obtenho os dados
                return new Aluno(resultado.getInt(MATRICULA_POSICAO_TABELA),
                                 resultado.getString(NOME_POSICAO_TABELA),
                                 resultado.getDate(NASCIMENTO_POSICAO_TABELA),
                                 resultado.getString(EMAIL_POSICAO_TABELA),
                                 resultado.getString(CURSO_POSICAO_TABELA)
                );
            }

            // Se chegou aqui é porque não tem aluno com essa matricula
            throw new AlunoNaoEncontradoException(matricula);
        } catch (SQLException e) {
            throw new Error(e.getMessage());
        }
    }

    /**
     * Insere um novo aluno no banco de dados.
     * @param aluno Aluno a ser persistido.
     * @throws AlunoExistenteException Aluno com a matricula informada já cadastrado.
     * @throws FalhaConexaoException Falha ao obter conexão com o SGBD.
     */
    public static void insere(Aluno aluno) throws AlunoExistenteException, FalhaConexaoException {

        try {
            // Estabelecer conexao
            Connection conexao = Conexao.obtemConexao();

            // Faço a consulta
            PreparedStatement stmt = conexao.prepareStatement("INSERT INTO alunos VALUES(?,?,?,?,?);");
            stmt.setInt(1, aluno.getMatricula());
            stmt.setString(2, aluno.getNome());
            stmt.setDate(3, new java.sql.Date(aluno.getDataNascimento().getTime()));
            stmt.setString(4, aluno.getEmail());
            stmt.setString(5, aluno.getCurso());
            stmt.execute();

        } catch (SQLException e) {
            if (e.getErrorCode() == DUPLICATE_KEY_ERROR_CODE) throw new AlunoExistenteException(aluno.getMatricula());
            throw new Error(e.getMessage());
        }
   }

    /**
     * Atualiza os dados de um aluno no banco de dados.
     * @param aluno Aluno a ser atualizado.
     * @throws AlunoNaoEncontradoException Não foi encontrado aluno com a matrícula especificada.
     * @throws FalhaConexaoException Falha ao obter conexão com o SGBD.
     */
   public static void atualiza(Aluno aluno) throws AlunoNaoEncontradoException, FalhaConexaoException {

        try {
            // Estabelecer conexao
            Connection conexao = Conexao.obtemConexao();

            // Faço a consulta
            PreparedStatement stmt = conexao.prepareStatement("UPDATE alunos SET nome = ?, data_nascimento = ?, email = ?, curso = ? WHERE matricula = ?;");
            stmt.setString(1, aluno.getNome());
            stmt.setDate(2, new java.sql.Date(aluno.getDataNascimento().getTime()));
            stmt.setString(3, aluno.getEmail());
            stmt.setString(4, aluno.getCurso());
            stmt.setInt(5, aluno.getMatricula());

            // Verifico a quantidade de registros alterados
            int nLinhasAlteradas = stmt.executeUpdate();
            
            // Se não alterou nenhuma linha é porque não tem aluno com essa matrícula
            if (nLinhasAlteradas == 0) throw new AlunoNaoEncontradoException(aluno.getMatricula());

        } catch (SQLException e) {
            throw new Error(e.getMessage());
        }    
   }

    /**
     * Remove o aluno do banco de dados.
     * @param aluno Aluno a ser removido.
     * @throws AlunoNaoEncontradoException Não foi encontrado aluno com a matrícula especificada.
     * @throws FalhaConexaoException Falha ao obter conexão com o SGBD.
     */
   public static void remove(Aluno aluno) throws AlunoNaoEncontradoException, FalhaConexaoException {

        try {
            // Estabelecer conexao
            Connection conexao = Conexao.obtemConexao();

            // Faço a consulta
            PreparedStatement stmt = conexao.prepareStatement("DELETE FROM alunos WHERE matricula = ?;");
            stmt.setInt(1, aluno.getMatricula());

            // Verifico a quantidade de registros alterados
            int nLinhasAlteradas = stmt.executeUpdate();
            
            // Se não alterou nenhuma linha é porque não tem aluno com essa matrícula
            if (nLinhasAlteradas == 0) throw new AlunoNaoEncontradoException(aluno.getMatricula());

        } catch (SQLException e) {
            throw new Error(e.getMessage());
        }   
   }

    /**
     * Obtem a lista de todos os alunos matriculados.
     * @return Lista de alunos matriculados.
     * @throws FalhaConexaoException Falha ao obter conexão com o SGBD.
     */
   public static List<Aluno> obtemListaAlunos() throws FalhaConexaoException {
   
           try {
            // Estabelecer conexao
            Connection conexao = Conexao.obtemConexao();

            // Faço a consulta
            Statement stmt = conexao.createStatement();
            ResultSet resultado = stmt.executeQuery("SELECT * from alunos ORDER BY nome;");

            // Crio a lista de alunos.
            List<Aluno> listaAlunos = new ArrayList<>();

            while(resultado.next()) {
                // Obtenho os dados
                Aluno alunoTmp = new Aluno(resultado.getInt(MATRICULA_POSICAO_TABELA),
                                           resultado.getString(NOME_POSICAO_TABELA),
                                           resultado.getDate(NASCIMENTO_POSICAO_TABELA),
                                           resultado.getString(EMAIL_POSICAO_TABELA),
                                           resultado.getString(CURSO_POSICAO_TABELA));
                // Adiciono à lista de alunos
                listaAlunos.add(alunoTmp);
            }

            // Retorna a lista de alunos preenchida
            return listaAlunos;

        } catch (SQLException e) {
            throw new Error(e.getMessage());
        }   
   }
}