<?php

$title = 'Index | MyFaceSpace';
include('includes/header.php');

if (!isset($_SESSION['login']) || $_SESSION['login'] !== true) {
    ?>

    <h1>You must be logged in to access this page</h1>
    <a href="login.php">Login</a>

    <?php
} else {

    require('date_util.php');
    require('database.php');
    $mysqli = ConnectToDatabase();

    $username = $_SESSION['username'];

    $sql = "SELECT name, status, updatetime FROM Users WHERE username='$username'";
    $result = $mysqli->query($sql)->fetch_object();

    $status = $result->status;
    $statusTime = $result->updatetime;

    ?>
    <br>
    <img src="images/<?php echo $username ?>.jpg">

    <h1><?php echo $username ?></h1>
    <p><?php echo nicetime($statusTime) ?></p>
    <p><?php echo $status ?></p>

    <form method="POST" action="set_status.php">
        <input type="text" name="status" required>
        <button>Update Status</button>
    </form>

    <h1>Your Friends</h1>

    <?php


    $sql = "SELECT * FROM
(SELECT u.username, u.name, u.status, u.updatetime FROM Users u, Friends f WHERE
f.username1='$username' AND f.username2 = u.username UNION
SELECT u.username, u.name, u.status, u.updatetime FROM Users u, Friends f WHERE
f.username2='$username' AND f.username1 = u.username) temp ORDER BY updatetime DESC";

    $result = $mysqli->query($sql);

    if ($result->num_rows === 0) {
        echo "<h3>You have no friends! <a href='add_friends.php'>Add some</a>!</h3>";
    }

    while ($row = $result->fetch_assoc()) {
        echo "<img src='images/" . $row['username'] . "_thumb.jpg'> <br>";
        echo $row['name'] . '<br>';
        echo nicetime($row['updatetime']) . '<br>';
        echo $row['status'] . '<br>';
        echo "<a class='removeButton' id='" . $row['username'] . "'>Remove Friend</a>";
        echo '<hr>';
    }

    ?>



    <?php
}
include("includes/footer.php");
?>