
package org.teiacoltec.poo.conexao;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;


public class Conexao {

    final private static String MYSQL_JDBC_DRIVER = "com.mysql.cj.jdbc.Driver";
    final private static int DB_PORT = 3306;
    final private static String DB_HOST = "localhost";
    final private static String DB_NAME = "coltec";

    // Bloco estático para carregamento do driver
    static {
         // Carrega o Driver do JDBC MYSQL
        try {
            Class.forName(MYSQL_JDBC_DRIVER);
        } catch (ClassNotFoundException ex) {
            System.err.println("Falha ao carregar o Driver do JDBC MySQL");
        }
    }

    static private Connection conexao = null;

    private Conexao() {}

    public static Connection obtemConexao() throws FalhaConexaoException {

        // Configurações de conexão
        String url = "jdbc:mysql:// " + DB_HOST + ":" + DB_PORT + "/" + DB_NAME;
        String usuario = "root";
        String senha = "senhaSuperSegura";

        try {
            if (conexao == null) {
                conexao = DriverManager.getConnection(url, usuario, senha);
            }
            return conexao;
        } catch (SQLException e) {
            throw new FalhaConexaoException(e.getMessage());
        }
    }

    public static void fechaConexao() {
        try {
        if (conexao != null) conexao.close();
        } catch (SQLException e) {
            // Faço nada
        }
    }



}