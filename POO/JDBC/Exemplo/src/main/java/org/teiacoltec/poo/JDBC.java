package org.teiacoltec.poo;

import org.teiacoltec.poo.alunoDAO.AlunoDAO;
import org.teiacoltec.poo.conexao.FalhaConexaoException;

/**
 *
 * @author Leandro
 */
public class JDBC {



    public static void main(String[] args) throws FalhaConexaoException {
        AlunoDAO.criaTabelaAluno();
    }
}
