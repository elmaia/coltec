/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */

package org.teiacoltec.poo;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

/**
 *
 * @author Leandro
 */
public class JDBC {

    final private static String MYSQL_JDBC_DRIVER = "com.mysql.cj.jdbc.Driver";
    final private static int DB_PORT = 3306;
    final private static String DB_HOST = "localhost";
    final private static String DB_NAME = "coltec";

    public static void main(String[] args) {
        
        // Configurações de conexão
        String url = "jdbc:mysql:// " + DB_HOST + ":" + DB_PORT + "/" + DB_NAME;
        String usuario = "root";
        String senha = "senhaSuperSegura";

        // Carrega o Driver do JDBC MYSQL
        try {
            Class.forName(MYSQL_JDBC_DRIVER);
        } catch (ClassNotFoundException ex) {
            System.err.println("Falha ao carregar o Driver do JDBC MySQL");
            return;
        }

        try {
            // Estabelece uma conexão
            Connection conexao = DriverManager.getConnection(url, usuario, senha);

            // Cria um statement para execução da query e executa
            Statement stmt = conexao.createStatement();            
            ResultSet tabelaAlunos = stmt.executeQuery("SELECT * FROM alunos");
            
            // Processar os resultados
            while (tabelaAlunos.next()) {
                System.out.println(tabelaAlunos.getInt("matricula") + " | " + tabelaAlunos.getString("nome") + " | " + tabelaAlunos.getString("senha"));
            }

            // Encerra os recursos utilizados
            tabelaAlunos.close();
            stmt.close();

            // Cria um novo registro
            PreparedStatement pstmt = conexao.prepareStatement("INSERT INTO alunos (matricula, nome, senha) VALUES (?,?,MD5(?))");
            pstmt.setInt(1, 2024950203);
            pstmt.setString(2, "Leandro Silva");
            pstmt.setString(3, "senhaQuaseSegura"); // MD5("senhaQuaseSegura")
            pstmt.executeUpdate();

            // Encerra os recursos utilizado
            pstmt.close();
            conexao.close();

        } catch (SQLException e) {
            System.out.println("Erro na conexão com o banco de dados: " + e.getMessage());
        }

    }
}
