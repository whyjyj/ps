-- 코드를 입력하세요
SELECT apnt.apnt_no, pt.pt_name, pt.pt_no, apnt.mcdp_cd, dr.dr_name, apnt.apnt_ymd
FROM appointment apnt
    JOIN patient pt
        ON apnt.pt_no = pt.pt_no
    JOIN doctor dr
        ON apnt.mddr_id = dr.dr_id
WHERE date_format(apnt.apnt_ymd, "%Y-%m-%d") = '2022-04-13'
    AND apnt.apnt_cncl_yn = "N"
    AND apnt.mcdp_cd = "CS"
ORDER BY apnt.apnt_ymd ASC