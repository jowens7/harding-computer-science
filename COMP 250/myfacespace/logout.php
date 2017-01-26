<?php

$title = 'Logout | MyFaceSpace';
include('includes/header.php');

if (isset($_SESSION['login']) && $_SESSION['login'] === true) {
    $_SESSION['login'] = false;
    $_SESSION['username'] = null;

    ?>

    <h1>You have been logged out.</h1>
    <a href="login.php">Login</a>

    <?php
} else {
    ?>

    <h1>You must be logged in to access this page</h1>
    <a href="login.php">Login</a>

    <?php
}
include('includes/footer.php');
?>
