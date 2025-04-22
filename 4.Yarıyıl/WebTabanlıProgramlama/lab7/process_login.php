<?php
include 'admin_config.php';

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    // Kullanıcı adı ve şifreyi al
    $username = $_POST['username'];
    $password = $_POST['password'];

    // Kullanıcı adı ve şifreyi doğrula
    if (isset($admins[$username]) && $admins[$username] === $password) {
        // Başarılı giriş
        echo "Başarıyla giriş yaptınız!";
        
        // Çerez oluştur
        setcookie("user_login", $username, time() + (86400 * 30), "/"); // 30 gün süreyle geçerli çerez

        // Kullanıcıyı yönlendir
        header("Location: welcome.php");
        exit;
    } else {
        // Hatalı giriş
        echo "Hatalı kullanıcı adı veya şifre!";
    }
}
?>
