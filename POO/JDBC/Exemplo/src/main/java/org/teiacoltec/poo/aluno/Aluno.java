package org.teiacoltec.poo.aluno;

import java.util.Date;

public class Aluno {

    /* Atributos */
    final private int matricula;
    private String nome;
    private Date dataNascimento;
    private String email;
    private String curso;

    /**
     * Construtor de Aluno.
     * @param matricula Matricula do aluno.
     * @param nome Nome do aluno.
     * @param dataNascimento Data de nascimento do aluno.
     * @param email Email do aluno.
     * @param curso Curso do aluno.
     */
    public Aluno(int matricula, String nome, Date dataNascimento, String email, String curso) {

        this.matricula = matricula;
        this.nome = nome;
        this.dataNascimento = (Date)dataNascimento.clone();
        this.email = email;
        this.curso = curso;
    }

    /* Getters e setters */
    public int getMatricula() {
        return this.matricula;
    }

    public String getNome() {
        return this.nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public Date getDataNascimento() {
        return (Date)this.dataNascimento.clone();
    }

    public void setDataNascimento(Date dataNascimento) {
        this.dataNascimento = (Date)dataNascimento.clone();
    }

    public String getEmail() {
        return this.email;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    public String getCurso() {
        return this.curso;
    }

    public void setCurso(String curso) {
        this.curso = curso;
    }

    /**
     * Método sobreescrito que transforma um aluno em uma representação 
     * de texto com todos seus dados.
     * @return Representação do aluno em texto.
     */
    @Override
    public String toString() {
        return "Aluno{" +
                "matricula=" + this.matricula + ", " + 
                "nome='" + this.nome + "'" + ", " + 
                "data_nascimento=" + this.dataNascimento.toString() + "," +
                "email='" + this.email + "'" + ", " + 
                "curso='" + this.curso + "'" + 
                '}';
    }
}