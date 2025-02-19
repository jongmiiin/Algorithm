SELECT ugb.TITLE,
        ugb.BOARD_ID, 
        ugr.REPLY_ID, 
        ugr.WRITER_ID, 
        ugr.CONTENTS, 
        date_format(ugr.created_date, '%Y-%m-%d') AS CREATED_DATE
FROM used_goods_board ugb, used_goods_reply ugr
WHERE ugb.board_id = ugr.board_id AND
        ugb.created_date LIKE '2022-10%'
ORDER BY ugr.CREATED_DATE, ugb.title