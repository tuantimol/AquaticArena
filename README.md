<h1> AQUATIC ARENA </h1>
<p align="center"><img src="https://github.com/tuantimol/AquaticArena/blob/main/src/background/name_game.png">

<h2> I. Giới thiệu tác giả:</h2>
<ul>
<li><b>Tên:</b> Nguyễn Anh Tuấn</li>
<li><b>Lớp:</b> K69I-CN2</li>
<li><b>MSSV:</b> 24022840</li>
</ul>

<h2>
 II. Tổng quan về trò chơi " AQUATIC ARENA "
</h2>
<ul>
 <li><b>Ngôn ngữ lập trình ra game:</b> C++ kết hợp với SDL2</li>
 <li><b>Nhân vật:</b> <p align="center"><img src=" https://github.com/tuantimol/AquaticArena/blob/main/src/image/PlayerImange.png " width=100></p>
 <li><b>Tóm tắt:</b> Di chuyển cá để ăn những con cá khác. Nếu cá của bạn ăn những con cá có số điểm được phép ăn nó sẽ nhận được điểm tương ứng với những con cá khác nhau. Ngược lại, bạn sẽ mất mạng. Nếu cá của bạn đạt 1000 điểm, bạn sẽ dành chiến thắng. Kích thước cá tăng theo từng mức điểm. Mặt khác, bạn sẽ thua khi bạn hết mạng. </li>
</ul>

<h2> III.Những điểm nổi bật trong game</h2>
<h3>Những loại cá có thể ăn</h3>
<b>Có 6 loại cá có trong game:</b>
<ul>
<li> <b>Minnow</b><p align="center"><img src="https://github.com/tuantimol/AquaticArena/blob/main/src/image/MinnowImage.png" width=100> </p>
Khi bạn ăn Minnow bạn sẽ được cộng thêm 5 điểm, nếu bạn đi qua Barra bạn sẽ bị trừ 10 máu.</li>
<li> <b>Barra</b><p align="center"><img src=" https://github.com/tuantimol/AquaticArena/blob/main/src/image/BarraImage.png" width=100> </p>
Khi bạn đạt được 100 điểm bạn sẽ được ăn thêm Barra và được cộng thêm 6 điểm, nếu va phải Orca bạn sẽ bị trừ 10 máu.</li>
<li> <b>Orca</b><p align="center"><img src=" https://github.com/tuantimol/AquaticArena/blob/main/src/image/OrcaImage.png" width=100> </p>
Khi bạn đạt được 300 điểm bạn sẽ được ăn thêm Orca và được cộng thêm 7 điểm, nếu va phải Marlin bạn sẽ bị trừ 10 máu.</li>
<li> <b>Marlin</b><p align="center"><img src=" https://github.com/tuantimol/AquaticArena/blob/main/src/image/MarlinImage.png" width=100> </p>
Khi bạn đạt được 500 điểm bạn sẽ được ăn thêm Marlin và được cộng thêm 8 điểm, nếu va phải LionFish bạn sẽ bị trừ 10 máu.</li>
<li> <b>LionFish</b><p align="center"><img src=" https://github.com/tuantimol/AquaticArena/blob/main/src/image/LionfishImage.png" width=100> </p>
Khi bạn đạt được 700 điểm bạn sẽ được ăn thêm LionFish và được cộng thêm 9 điểm, nếu va phải Shark bạn sẽ bị trừ 10 máu.</li>
<li> <b>Shark</b><p align="center"><img src=" https://github.com/tuantimol/AquaticArena/blob/main/src/image/LionfishImage.png" width=100> </p>
Khi bạn đạt được 900 điểm bạn sẽ được ăn thêm Shark và được cộng thêm 10 điểm.</li>
<li> <b>Bomb</b><p align="center"><img src=" https://github.com/tuantimol/AquaticArena/blob/main/src/image/LionfishImage.png" width=100> </p>
Khi bạn đạt được 900 điểm cũng sẽ là lúc Bomb xuất hiện và khi bạn va phải Bomb bạn sẽ mất 20 máu.</li>
</ul>

<h3>Một số tính năng nổi bật khác:</h3>
Kích thước cá của bạn có thể thay đổi.
 <li>Bot có thể theo dõi vị trí của cá.  </li>
 <li>Khi có thể ăn một con cá, nó sẽ quay lại khi di chuyển gần đến cá của bạn.  </li>
 <li>Có hiệu ứng âm thanh khi cá của bạn ăn một con cá khác và cá của bạn va chạm với quả bomb.  </li>
 <li>Bot xuất hiện ngẫu nhiên dựa trên điểm của bạn. Điểm của bạn càng cao, càng có nhiều cá lớn hơn xuất hiện.  </li>

<h3>Âm thanh</h3>
<ul>
 <li> Ở <b>Menu</b> góc dưới màn hình bên phải có 2 buttons mute hoặc unmute. Người chơi ấn button đó sẽ chuyển trạng thái </li>
</ul>

<h3>Cách tạm dừng game</h3>
Người chơi có thể click chuột trái vào pause button, khi đó game sẽ tạm dừng
<h2>IV. Tài liệu tham khảo</h2>
<ul>
<li> Code mẫu tham khảo trên <a href=" https://lazyfoo.net/tutorials/SDL/"> Lazy Foo' Productions </a>
 <li> Tài nguyên Sprites và Background lấy từ <a href="https://www.spriters-resource.com/pc_computer/feedingfrenzy/"> The Spriters Resource </a></li>
 <li> Phông chữ trong trò chơi được tải từ <a href=" https://www.dafont.com/">Dafont</a></li>
 <li> Nhạc nền menu và sound effect tự thu âm </li>
</ul></h2>
