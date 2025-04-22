<?php
// Çerez süresini geçmiş bir tarih ile ayarlayarak çerezi sil
setcookie("user_login", "", time() - 3600, "/"); // Geçmiş bir tarih ile çerezi sil

// Kullanıcıyı yönlendir
header("Location: login_form.php");
exit;
?>
