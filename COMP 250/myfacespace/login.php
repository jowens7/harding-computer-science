<?php

$title = 'Login | MyFaceSpace';
include('includes/header.php');

if (isset($_SESSION['login']) && $_SESSION['login'] === true) {
    header('Location: index.php');
}

if ($_SERVER['REQUEST_METHOD'] === 'POST') {

    require('database.php');
    $mysqli = ConnectToDatabase();

    if (isset($_POST['username'])) {
        $username = $_POST['username'];
    }

    if (isset($_POST['password'])) {
        $password = $_POST['password'];
    }

    if (isset($username) && isset($password)) {

        $sql = "SELECT * FROM Users WHERE username='$username'";
        $result = $mysqli->query($sql);

        if ($result->num_rows === 0) {
            echo 'Incorrect username or password';
        } else {
            $resultSet = $result->fetch_object();
            if (password_verify($password, $resultSet->password)) {
                $_SESSION['login'] = true;
                $_SESSION['username'] = $resultSet->username;
                header('Location: index.php');
            } else {
                echo 'Incorrect username or password';
            }
        }

        $result->close();

    } else {
        echo 'Please enter a username and password';
    }

}

?>

    <h1>Welcome to MyFaceSpace</h1>
    <h2>Login</h2>

    <form method="POST" action="login.php">
        <input type="text" name="username" value="<?php if (isset($username)) { echo $username; } ?>" autofocus required>
        <input type="password" name="password" required>
        <button>Login</button>
    </form>
    <a href="create_account.php">Create an account</a>

<?php
include('includes/footer.php');
?>