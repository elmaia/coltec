/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

package org.teiacoltec.poo.externalizable;

import java.io.Externalizable;
import java.io.IOException;
import java.io.ObjectInput;
import java.io.ObjectOutput;

/**
 *
 * @author Leandro
 */
public class Aluno implements Externalizable {

    // Versão da classe
    final private static long serialVersionUID = 10000L;

    // Senha padrão caso o aluno não especifique a senha
    final private static String SENHA_PADRAO = "semSenha";

    private String nome;
    private int matricula;    // Aqui não pode mais ser final mesmo eu não alterando a matrícula
    private String senha;     // Não faz diferença porque eu que controlo o que vai ou não ser serializado


    // Esse construtor padrão é necessário por conta do Externalizable
    // Como a serialização é feita na mão, na desserialização é necessário
    // criar um objeto com os valores padrões para depois ir trocando os dados
    // conforme a necessidade.
    // Comente a linha abaixo e rode novamente o teste para ver a exceção acontecer
    public Aluno() { }

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

    @Override
    public void writeExternal(ObjectOutput out) throws IOException {
        out.writeObject(nome);
        out.writeInt(matricula);
    }

    @Override
    public void readExternal(ObjectInput in) throws IOException, ClassNotFoundException {
        nome = (String) in.readObject();
        matricula = in.readInt();
    }
}
