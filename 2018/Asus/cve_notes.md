This notes are here to disclose 3 CVEs for Asus routers that leaded to authenticated remote code execution and information disclosure. These vulnerabilities initially were found in AsusWRT Merlin and, it turned out, that these vulnerabilities were present in vanila firmware as well.

CVE-2018-8879 - Buffer overflow vulnerability -> remote code execution

CVE-2018-8879 was described in details in the article "The Router Security Is Decadent and Depraved" at PagedOut! magazine. Link for the article:
https://pagedout.institute/download/PagedOut_001_beta1.pdf

This is a buffer overflow vulnerability in blocking.asp page that is publicly available for non-authenticated users.There are three parameters that a vulnerable as follows: flag, mac, cat_id.
All of these parameters are supplied with long enough buffer triggers a crash within httpds daemon with arbitrary overwrite of PC register that could lead to remote code execution.

The exploit could be found within the article itself.
(See pictures: rce_debugger_crash.png)

CVE-2018-8877 - IP disclosure
CVE-2018-8878 - MAC disclosure

Two other vulnerabilities disclose internal general IP-range and also MAC-addresses and hostnames of devices, connected to the router. MAC-addresses could be seen after accessing same blocking.asp page, they located at custom_id variable and being URL decoded.
IP-address is visible at error_page.htm at new_lan_ip variable.

Since both pages are, again, available to non-authenticated user so could potentially be classified as information leakage.
(See pictures: disclosure_1.png, disclosure_2.png in the repo)

Additional links:

Fix in Asus Merlin: https://www.asuswrt-merlin.net/changelog-382

Fix in Asus stock firmware, sample: https://www.asus.com/Networking/RTAC66U/HelpDesk_BIOS/

These vulnerablities were found with help of Andrey Basarygin.
