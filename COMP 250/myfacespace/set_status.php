<?php

session_start();

if (isset($_SESSION['login']) && $_SESSION['login'] === true) {

    require('database.php');
    $mysqli = ConnectToDatabase();

    if (isset($_POST['status'])) {
        $status = $_POST['status'];
    }

    if (isset($status)) {

        $ps = $mysqli->prepare('UPDATE Users SET status=?, updatetime=NOW() WHERE username=?');

        $ps->bind_param(
            'ss',
            $status,
            $_SESSION['username']
        );

        $ps->execute();

    } else {
        echo 'Invalid POST data';
    }

}

header('Location: login.php');

?>