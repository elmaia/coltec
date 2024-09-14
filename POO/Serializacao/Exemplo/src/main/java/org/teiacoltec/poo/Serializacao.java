/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */

package org.teiacoltec.poo;

import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;

/**
 *
 * @author Leandro
 */
public class Serializacao {

    final private static String NOME_ARQUIVO_ALUNO_SERIALIZABLE = "./aluno.ser";
    final private static String NOME_ARQUIVO_ALUNO_EXTERNALIZABLE = "./aluno.xser";

    public static void usoAlunoSerializable() {

        // Crio um novo aluno usando senha padrão
        org.teiacoltec.poo.serializable.Aluno aluno = new org.teiacoltec.poo.serializable.Aluno(2024950102, "Leandro Maia");
        // Imprimo seus dados para ver quais são os valores originais
        System.out.println(aluno);

        try {
            // Abro arquivo para receber os dados do aluno
            FileOutputStream arquivoAluno = new FileOutputStream(NOME_ARQUIVO_ALUNO_SERIALIZABLE);
            // Associo o stream de serialização ao arquivo
            ObjectOutputStream serializador = new ObjectOutputStream(arquivoAluno);
            // Serializo o objeto
            serializador.writeObject(aluno);
            // Fecho o objeto de serialização
            serializador.close();
            // Fecho o arquivo de saída
            arquivoAluno.close();

            // Interação com o usuário dando feedback
            System.out.println("Objeto aluno serializado com sucesso!");

        } catch (IOException e) {
            System.err.println("Erro ao serializar o objeto Aluno.");
            System.err.println(e.getMessage());
        }

        try {
            
            // Abro arquivo para ler os dados do aluno
            FileInputStream arquivoAluno = new FileInputStream(NOME_ARQUIVO_ALUNO_SERIALIZABLE);
            // Associo o stream de desserialização ao arquivo
            ObjectInputStream desserializador = new ObjectInputStream(arquivoAluno);
            // Desserializo e faço o cast porque readObject retorna Object e eu preciso de Aluno
            org.teiacoltec.poo.serializable.Aluno alunoDesserializado = (org.teiacoltec.poo.serializable.Aluno) desserializador.readObject();
            // Fecho o objeto de desserialização
            desserializador.close();
            // Fecho o arquivo de entrada
            arquivoAluno.close();

            // Interação com o usuário dando feedback
            System.out.println("Objeto aluno desserializado com sucesso!");

            // Interação com o usuário
            System.out.println(alunoDesserializado);

        } catch (IOException | ClassNotFoundException e) {
            System.err.println("Erro ao desserializar o objeto Aluno.");
            System.err.println(e.getMessage());
        }

    }

    public static void usoAlunoExternalizable() {

        // Crio um novo aluno usando senha padrão
        org.teiacoltec.poo.externalizable.Aluno aluno = new org.teiacoltec.poo.externalizable.Aluno(2024950102, "Leandro Maia");
        // Imprimo seus dados para ver quais são os valores originais
        System.out.println(aluno);

        try {
            // Abro arquivo para receber os dados do aluno
            FileOutputStream arquivoAluno = new FileOutputStream(NOME_ARQUIVO_ALUNO_EXTERNALIZABLE);
            // Associo o stream de serialização ao arquivo
            ObjectOutputStream serializador = new ObjectOutputStream(arquivoAluno);
            // Serializo o objeto
            serializador.writeObject(aluno);
            // Fecho o objeto de serialização
            serializador.close();
            // Fecho o arquivo de saída
            arquivoAluno.close();

            // Interação com o usuário dando feedback
            System.out.println("Objeto aluno serializado com sucesso!");

        } catch (IOException e) {
            System.err.println("Erro ao serializar o objeto Aluno.");
            System.err.println(e.getMessage());
        }

        try {
            
            // Abro arquivo para ler os dados do aluno
            FileInputStream arquivoAluno = new FileInputStream(NOME_ARQUIVO_ALUNO_EXTERNALIZABLE);
            // Associo o stream de desserialização ao arquivo
            ObjectInputStream desserializador = new ObjectInputStream(arquivoAluno);
            // Desserializo e faço o cast porque readObject retorna Object e eu preciso de Aluno
            org.teiacoltec.poo.externalizable.Aluno alunoDesserializado = (org.teiacoltec.poo.externalizable.Aluno) desserializador.readObject();
            // Fecho o objeto de desserialização
            desserializador.close();
            // Fecho o arquivo de entrada
            arquivoAluno.close();

            // Interação com o usuário dando feedback
            System.out.println("Objeto aluno desserializado com sucesso!");

            // Interação com o usuário
            System.out.println(alunoDesserializado);

        } catch (IOException | ClassNotFoundException e) {
            System.err.println("Erro ao desserializar o objeto Aluno.");
            System.err.println(e.getMessage());
        }

    }
    public static void main(String[] args) {

        System.out.println("Usando Serializable...");
        usoAlunoSerializable();

        System.out.println();
        System.out.println("Usando Externalizable...");
        usoAlunoExternalizable();

    }
}
