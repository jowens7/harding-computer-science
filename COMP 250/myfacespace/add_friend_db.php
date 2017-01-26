<?php

session_start();

if (isset($_SESSION['login']) && $_SESSION['login'] === true) {

    require('database.php');
    $mysqli = ConnectToDatabase();

    if (isset($_GET['username'])) {
        $usernameToFriend = $_GET['username'];
    }

    if (isset($usernameToFriend)) {

        $ps = $mysqli->prepare('INSERT INTO Friends VALUES (?, ?)');

        $ps->bind_param(
            'ss',
            $_SESSION['username'],
            $usernameToFriend
        );

        $ps->execute();

        echo 'OK';

    } else {
        echo 'Invalid GET data';
    }

}
?>