<?php

session_start();

if (isset($_SESSION['login']) && $_SESSION['login'] === true) {

    require('database.php');
    $mysqli = ConnectToDatabase();

    if (isset($_GET['username'])) {
        $friendToRemove = $_GET['username'];
    }

    if (isset($friendToRemove)) {

        $ps = $mysqli->prepare('DELETE FROM Friends WHERE (username1=? AND username2=?) OR
(username1=? AND username2=?)');

        $ps->bind_param(
            'ssss',
            $_SESSION['username'],
            $friendToRemove,
            $friendToRemove,
            $_SESSION['username']
        );

        $ps->execute();

    } else {
        echo 'Invalid POST data';
    }

}
header('Location: index.php');
?>