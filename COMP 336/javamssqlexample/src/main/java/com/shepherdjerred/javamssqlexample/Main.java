package com.shepherdjerred.javamssqlexample;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class Main {

    public static void main(String args[]) {

        String connectionUrl = "jdbc:sqlserver://csdb2.harding.edu:1433;databaseName=team4;user=student;password=sqlserver";

        try {
            Connection connection = DriverManager.getConnection(connectionUrl);
            new DatabaseDemo(connection).runDemo();
        } catch (SQLException e) {
            e.printStackTrace();
        }

    }

}
