package com.shepherdjerred.javamssqlexample;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;

public class DatabaseDemo {

    private final Connection connection;

    public DatabaseDemo(Connection connection) {
        this.connection = connection;
    }

    public void runDemo() throws SQLException {

        createStudentsTable();

        createStudent("John Doe");
        printStudents();

        updateStudent("John Doe", "Jane Doe");
        printStudents();

        deleteStudent("Jane Doe");
        printStudents();

        dropStudentsTable();

    }

    private void dropStudentsTable() throws SQLException {
        String dropStudents = "DROP TABLE students";
        connection.createStatement().executeUpdate(dropStudents);
    }

    private void createStudentsTable() throws SQLException {
        String createStudents = "CREATE TABLE students (uuid CHAR(36) PRIMARY KEY DEFAULT newid(), name TEXT)";
        connection.createStatement().executeUpdate(createStudents);
    }

    private void createStudent(String name) throws SQLException {

        String insertStudent = "INSERT INTO students (name) VALUES (?)";

        PreparedStatement ps = connection.prepareStatement(insertStudent);
        ps.setString(1, name);
        ps.execute();

    }

    private void updateStudent(String currentName, String newName) throws SQLException {

        String updateStudent = "UPDATE students SET name = ? WHERE name LIKE ?";

        PreparedStatement ps = connection.prepareStatement(updateStudent);
        ps.setString(1, newName);
        ps.setString(2, currentName);
        ps.execute();

    }

    private void deleteStudent(String name) throws SQLException {

        String deleteStudent = "DELETE FROM students WHERE name LIKE ?";

        PreparedStatement ps = connection.prepareStatement(deleteStudent);
        ps.setString(1, name);
        ps.execute();

    }

    private List<String> selectStudents() throws SQLException {
        List<String> students = new ArrayList<>();

        String selectStudents = "SELECT * FROM students";
        ResultSet rs = connection.createStatement().executeQuery(selectStudents);

        while (rs.next()) {
            students.add(rs.getString("name"));
        }

        return students;
    }

    private void printStudents() throws SQLException {
        System.out.println(selectStudents().toString());
    }

}
