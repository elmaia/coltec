/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

package org.teiacoltec.poo.serializable;

import java.io.Serializable;

/**
 *
 * @author Leandro
 */
public class Aluno implements Serializable {

    // Versão da classe
    final private static long serialVersionUID = 10000L;

    // Senha padrão caso o aluno não especifique a senha
    final private static String SENHA_PADRAO = "semSenha";

    private String nome;
    final private int matricula;    // Matrícula nunca é alterado, então pode ser final
    private transient String senha; // Campo transient não será serializado

    public Aluno(int matricula, String nome) {
        this(matricula, nome, SENHA_PADRAO);
    }

    public Aluno(int matricula, String nome, String senha) {
        this.nome = nome;
        this.matricula = matricula;
        this.senha = senha;
    }

    // Getters e setters   
    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public int getMatricula() {
        return matricula;
    }

    public void setSenha(String senha) {
        this.senha = senha;
    }

    public boolean verificaSenha(String senha) {
        return this.senha.compareTo(senha) == 0;
    }

    @Override
    public String toString() {
        return "Aluno{" +
                "matricula=" + matricula + ", " + 
                "nome='" + nome + "'" + ", " + 
                "senha=" + senha +
                '}';
    }
}
