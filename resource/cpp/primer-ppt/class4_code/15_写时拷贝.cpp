void reverse() {
		if (*count > 1) { //�����Լ��⣬����������
			//���¸���һ���Ժ��ٴ���
			(*count)--; //�Ȱ��Լ��ļ���ȥ��
			count = new int(1); //���¿����µļ����ռ�
			char* tmp = ps; //����ԭ����psָ��ָ���λ��
			ps = new char[strlen(tmp) + 1];
			strcpy(ps, tmp);
			//��ʱ���������Ѿ�������һ�ݿ��������¿��˼�����
		}
		int len = strlen(ps) - 1;
		for (int i = 0; i < len / 2; i++) {
			char c = ps[i];
			ps[i] = ps[len - i];
			ps[len - i] = c;
		}
	}