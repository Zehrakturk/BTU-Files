<?php
// Eğer kullanıcı giriş yapmışsa
if (isset($_COOKIE['user_login'])) {
    echo "Giriş yapıldı. Çıkış yapmak için <a href='logout.php'>buraya tıklayın</a>.";
} else {
    // Kullanıcı giriş yapmamışsa, giriş sayfasına yönlendir
    header("Location: login_form.php");
    exit;
}
?>
